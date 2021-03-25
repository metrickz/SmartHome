package com.obert.smarthome;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextUtils;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Settings extends AppCompatActivity {

    Button save;
    EditText ipAddr;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.settings);
        save = findViewById(R.id.btn_save);
        ipAddr = findViewById(R.id.et_ipAddr);



        SharedPreferences settings = getSharedPreferences("UserInfo", 0);
        ipAddr.setText(settings.getString("IP", "").toString());




        save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String enteredIP = ipAddr.getText().toString().trim();
                if(TextUtils.isEmpty(enteredIP)){
                    ipAddr.setError("Please enter a valid IP");
                }else{
                    SharedPreferences.Editor editor = settings.edit();
                    editor.putString("IP",ipAddr.getText().toString());
                    editor.apply();
                    finish();
                    Intent intent = new Intent(Settings.this, MainActivity.class);
                    startActivity(intent);
                }


            }
        });

    }
}