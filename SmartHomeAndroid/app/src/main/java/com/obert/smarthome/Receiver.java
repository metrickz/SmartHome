package com.obert.smarthome;

import android.content.Context;
import android.os.Handler;
import android.util.Log;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


public class Receiver implements Runnable{

    ServerSocket serverSocket;
    Socket socket;
    DataInputStream dataInputStream;
    String message;
    Handler handler = new Handler();


    @Override
    public void run() {
        try{
            serverSocket = new ServerSocket(1337);
            handler.post(new Runnable() {
                @Override
                public void run() {
                    Log.d("DATA","Waiting for client...");
                }
            });

            while(true){
                socket = serverSocket.accept();
                dataInputStream = new DataInputStream(socket.getInputStream());
                message = dataInputStream.readUTF();

                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        Log.d("DATA",message);
                    }
                });
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
