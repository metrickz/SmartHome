package com.obert.smarthome;

import android.os.AsyncTask;
import android.util.Log;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;

public class Sender extends AsyncTask<String, Void, Void> {

    Socket socket;
    DataOutputStream dataOutputStream;
    PrintWriter printWriter;

    @Override
    protected Void doInBackground(String... voids) {

        String data = voids[0];

        try {
            socket = new Socket("10.0.2.2",1337);
            printWriter = new PrintWriter(socket.getOutputStream());
            printWriter.println(data);
            printWriter.flush();
            printWriter.close();
            socket.close();
            Log.d("DATA","Data written");

        } catch (IOException e) {
            e.printStackTrace();
            Log.d("DATA","Error");
        }

        return null;
    }
}
