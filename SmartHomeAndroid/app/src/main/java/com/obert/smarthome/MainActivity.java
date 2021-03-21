package com.obert.smarthome;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;

public class MainActivity extends AppCompatActivity {

    Button lightsOff, lightsOn, shuttersUp, shuttersDown, tiltWindow, btn_settings;
    SeekBar light, setTemp;
    NetworkTask networkTask;

    char startCharacter = '<';
    char endCharacter = '>';

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Check if IP is empty
        SharedPreferences settings = getSharedPreferences("UserInfo", 0);
        String savedIP = settings.getString("IP","");
        Log.i("AsyncTask","IP: "+savedIP);

        if(savedIP.equals("")){
            Intent intent = new Intent(MainActivity.this, Settings.class);
            startActivity(intent);
        }

        // Buttons
        lightsOff = findViewById(R.id.btn_lightOff);
        lightsOn = findViewById(R.id.btn_lightOn);
        shuttersUp = findViewById(R.id.btn_shuttersUp);
        shuttersDown = findViewById(R.id.btn_shuttersDown);
        tiltWindow = findViewById(R.id.btn_tiltWindow);
        btn_settings = findViewById(R.id.btn_settings);

        // Seekbars
        light = findViewById(R.id.seekBar_light);
        setTemp = findViewById(R.id.seekBar_setTemp);

        networkTask = new NetworkTask(MainActivity.this,this);
        networkTask.execute(savedIP);





        btn_settings.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, Settings.class);
                startActivity(intent);
            }
        });


       lightsOff.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View view) {
               String device = Integer.toBinaryString(1);
               String value = Integer.toBinaryString(0);
               String message = startCharacter+device+":"+value+endCharacter;
               networkTask.SendDataToNetwork(message.getBytes());
               lightsOff.setEnabled(false);
               lightsOn.setEnabled(true);
           }
       });

        lightsOn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String device = Integer.toBinaryString(1);
                String value = Integer.toBinaryString(255);
                String message = startCharacter+device+":"+value+endCharacter;
                networkTask.SendDataToNetwork(message.getBytes());
                lightsOff.setEnabled(true);
                lightsOn.setEnabled(false);
            }
        });

        light.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int setLight = 20;

            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                setLight = i;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                String device = Integer.toBinaryString(1);
                String value = Integer.toBinaryString(setLight);
                String message = startCharacter+device+":"+value+endCharacter;
                networkTask.SendDataToNetwork(message.getBytes());
            }
        });

        shuttersDown.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String device = Integer.toBinaryString(2);
                String value = Integer.toBinaryString(1);
                String message = startCharacter+device+":"+value+endCharacter;
                networkTask.SendDataToNetwork(message.getBytes());
                shuttersDown.setEnabled(false);
                shuttersUp.setEnabled(true);
            }
        });

        shuttersUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String device = Integer.toBinaryString(2);
                String value = Integer.toBinaryString(0);
                String message = startCharacter+device+":"+value+endCharacter;
                networkTask.SendDataToNetwork(message.getBytes());
                shuttersDown.setEnabled(true);
                shuttersUp.setEnabled(false);
            }
        });

        tiltWindow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String device = Integer.toBinaryString(3);

                Log.i("AsyncTask",tiltWindow.getText().toString() );
                if(tiltWindow.getText().toString().equals("TILT")){
                    String value = Integer.toBinaryString(1);
                    String message = startCharacter+device+":"+value+endCharacter;
                    networkTask.SendDataToNetwork(message.getBytes());
                    tiltWindow.setText("CLOSE");
                }else{
                    String value = Integer.toBinaryString(0);
                    String message = startCharacter+device+":"+value+endCharacter;
                    networkTask.SendDataToNetwork(message.getBytes());
                    tiltWindow.setText("TILT");
                }

            }
        });

        setTemp.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int setpointTemperature;

            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                setpointTemperature = i;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                String device = Integer.toBinaryString(4);
                String value = Integer.toBinaryString(setpointTemperature);
                String message = startCharacter+device+":"+value+endCharacter;
                networkTask.SendDataToNetwork(message.getBytes());
            }
        });

    }
};

