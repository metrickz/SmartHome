package com.obert.smarthome;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;

public class NetworkTask extends AsyncTask<String, byte[], Boolean> {
    Context context;
    Activity activity;
    Socket socket; //Network Socket
    InputStream inputStream; //Network Input Stream
    DataInputStream dis;
    OutputStream outputStream; //Network Output Stream

    Button lightsOff, lightsOn, shuttersUp, shuttersDown, tiltWindow, btn_settings;
    SeekBar light, setTemp;
    ProgressBar shuttersProgress;

    TextView lbl_temp, lbl_humidity, lbl_brightness, lbl_airpressure;


    public NetworkTask(Context mCtx, Activity mActivity){
        context = mCtx;
        activity = mActivity;
    }


    @Override
    protected void onPreExecute() {
        Log.i("AsyncTask", "onPreExecute");
    }

    @Override
    protected Boolean doInBackground(String... params) { //This runs on a different thread
        boolean result = false;
        String ip = params[0];
        try {
            Log.i("AsyncTask", "doInBackground: Creating socket");
            socket = new Socket(ip,9600);
            if (socket.isConnected()) {
                inputStream = socket.getInputStream();
                //dis = new DataInputStream(inputStream);
                //Log.i("AsyncTask", "DIS: "+dis.readUTF());
                outputStream = socket.getOutputStream();
                Log.i("AsyncTask", "doInBackground: Socket created on "+ip);
                Log.i("AsyncTask", "doInBackground: Waiting for inital data...");

                byte[] buffer = new byte[4096];
                int read = inputStream.read(buffer, 0, 4096); //This is blocking
                while(read != -1){
                    byte[] tempdata = new byte[read];
                    System.arraycopy(buffer, 0, tempdata, 0, read);
                    publishProgress(tempdata);
                    Log.i("AsyncTask", "doInBackground: Got some data");
                    read = inputStream.read(buffer, 0, 4096); //This is blocking
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
            Log.i("AsyncTask", "doInBackground: IOException");
            result = true;
        } catch (Exception e) {
            e.printStackTrace();
            Log.i("AsyncTask", "doInBackground: Exception");
            result = true;
        } finally {
            try {
                inputStream.close();
                outputStream.close();
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (Exception e) {
                e.printStackTrace();
            }
            Log.i("AsyncTask", "doInBackground: Finished");
        }
        return result;
    }

    public boolean SendDataToNetwork(final byte[] cmd) {
        if (socket.isConnected()) {
            Log.i("AsyncTask", "SendDataToNetwork: Writing received message to socket");
            new Thread(new Runnable() {
                public void run() {
                    try {
                        outputStream.write(cmd);
                    } catch (Exception e) {
                        e.printStackTrace();
                        Log.i("AsyncTask", "SendDataToNetwork: Message send failed. Caught an exception");
                    }
                }
            }).start();

            return true;
        }

        Log.i("AsyncTask", "SendDataToNetwork: Cannot send message. Socket is closed");
        return false;
    }

    @Override
    protected void onProgressUpdate(byte[]... values) {
        // Buttons
        lightsOff = activity.findViewById(R.id.btn_lightOff);
        lightsOn = activity.findViewById(R.id.btn_lightOn);
        shuttersUp = activity.findViewById(R.id.btn_shuttersUp);
        shuttersDown = activity.findViewById(R.id.btn_shuttersDown);
        tiltWindow = activity.findViewById(R.id.btn_tiltWindow);
        btn_settings = activity.findViewById(R.id.btn_settings);

        // Seekbars
        light = activity.findViewById(R.id.seekBar_light);
        setTemp = activity.findViewById(R.id.seekBar_setTemp);
        shuttersProgress = activity.findViewById(R.id.shuttersPosition);

        // Labels
        lbl_temp = activity.findViewById(R.id.lbl_showTemp);
        lbl_humidity = activity.findViewById(R.id.lbl_showHumidity);
        lbl_brightness = activity.findViewById(R.id.lbl_showBrightness);
        lbl_airpressure = activity.findViewById(R.id.lbl_showAirPressure);

        if (values.length > 0) {
            String recv = null;
            String msg = "";

            try {
                recv = new String(values[0], "UTF-8");       // Convert incoming bytes into UTF8 String
                Log.i("AsyncTask", "Received data: " + recv);


                boolean startMessage = false;

                for(int i=0;i<recv.length();i++){
                    if(recv.charAt(i) == '<'){
                        startMessage = true;
                    }
                    if(!(recv.charAt(i) == '>') && recv.charAt(i) != '<' && startMessage==true){
                        msg += recv.charAt(i);
                    }else if(recv.charAt(i) == '>')
                    {
                        if(!msg.isEmpty() && msg.contains(":"))
                        {
                            String[] keypair = msg.split(":");
                            Log.i("AsyncTask", "Device: " + keypair[0] + " Value: "+ keypair[1]);

                            int device = Integer.parseInt(keypair[0]);
                            int value = Integer.parseInt(keypair[1]);

                            switch(device){

                                //Lights
                                case 1:
                                    if(value==0){
                                        lightsOff.setEnabled(false);
                                        lightsOn.setEnabled(true);
                                    }else if(value==255){
                                        lightsOff.setEnabled(true);
                                        lightsOn.setEnabled(false);
                                    }else{
                                        lightsOff.setEnabled(true);
                                        lightsOn.setEnabled(true);
                                    }
                                    light.setProgress(value);
                                    break;
                                //Shutters
                                case 2:
                                    if(value==0){
                                        shuttersUp.setEnabled(false);
                                        shuttersDown.setEnabled(true);
                                    }else if(value==1){
                                        shuttersUp.setEnabled(true);
                                        shuttersDown.setEnabled(false);
                                    }
                                    break;
                                case 3:
                                    if(value==0){
                                        tiltWindow.setText("Tilt");
                                    }else if(value==1){
                                        tiltWindow.setText("Close");
                                    }
                                    break;
                                case 4:
                                    setTemp.setProgress(value);
                                    break;
                                case 5:
                                    lbl_temp.setText(String.valueOf(value)+"°C");
                                    break;
                                case 6:
                                    lbl_humidity.setText(String.valueOf(value)+"%");
                                    break;
                                case 7:
                                    lbl_brightness.setText(String.valueOf(value));
                                    break;
                                case 8:
                                    lbl_airpressure.setText(String.valueOf(value));
                                    break;
                                case 9:
                                    shuttersProgress.setProgress(value);
                            }
                        }
                        msg = "";
                        startMessage = false;
                    }
                }


                /*
                if(message.startsWith("<") && message.endsWith(">") && message.contains(":")){
                    message = message.replace("<", "");
                    message = message.replace(">", "");
                    String[] keyPair = message.split("\\:");            // split message into device and its value
                    String device_str = keyPair[0];
                    String value_str = keyPair[1];
                    Log.i("AsyncTask", "Device: " + device_str + " Value: "+ value_str);

                    int device = Integer.parseInt(device_str);
                    int value = Integer.parseInt(value_str);

                    switch(device){

                        //Lights
                        case 1:
                            if(value==0){
                                lightsOff.setEnabled(false);
                                lightsOn.setEnabled(true);
                            }else if(value==255){
                                lightsOff.setEnabled(true);
                                lightsOn.setEnabled(false);
                            }else{
                                lightsOff.setEnabled(true);
                                lightsOn.setEnabled(true);
                            }
                            light.setProgress(value);
                            break;
                        //Shutters
                        case 2:
                            if(value==0){
                                shuttersUp.setEnabled(false);
                                shuttersDown.setEnabled(true);
                            }else if(value==1){
                                shuttersUp.setEnabled(true);
                                shuttersDown.setEnabled(false);
                            }
                            break;
                        case 3:
                            if(value==0){
                                tiltWindow.setText("Tilt");
                            }else if(value==1){
                                tiltWindow.setText("Close");
                            }
                            break;
                        case 4:
                            setTemp.setProgress(value);
                    }
                }*/
            } catch (UnsupportedEncodingException e) {
                e.printStackTrace();
            }
        }
    }
    @Override
    protected void onCancelled() {
        Log.i("AsyncTask", "Cancelled.");
        //btnStart.setVisibility(View.VISIBLE);
    }
    @Override
    protected void onPostExecute(Boolean result) {
        if (result) {
            Log.i("AsyncTask", "onPostExecute: Completed with an Error.");
            //textStatus.setText("There was a connection error.");
        } else {
            Log.i("AsyncTask", "onPostExecute: Completed.");
        }
        //btnStart.setVisibility(View.VISIBLE);
    }

}