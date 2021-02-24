package com.obert.smarthome;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;

public class MainActivity extends AppCompatActivity {

    Button lightsOff, lightsOn, shuttersUp, shuttersDown, tiltWindow;
    SeekBar light, setTemp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Buttons
        lightsOff = findViewById(R.id.btn_lightOff);
        lightsOn = findViewById(R.id.btn_lightOn);
        shuttersUp = findViewById(R.id.btn_shuttersUp);
        shuttersDown = findViewById(R.id.btn_shuttersDown);
        tiltWindow = findViewById(R.id.btn_tiltWindow);

        // Seekbars
        light = findViewById(R.id.seekBar_light);
        setTemp = findViewById(R.id.seekBar_setTemp);





       lightsOff.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View view) {
               Sender sender = new Sender();
               sender.execute("TestString");
               Log.d("DATA","Executed");
           }
       });
    }


}