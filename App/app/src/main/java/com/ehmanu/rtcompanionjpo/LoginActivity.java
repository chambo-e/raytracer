package com.ehmanu.rtcompanionjpo;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends Activity {

    private EditText edit_ip;

    private final BroadcastReceiver receiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            Bundle bundle = intent.getExtras();
            if (bundle != null) {
                boolean result = bundle.getBoolean(ConnectService.RESPONSE);
                if (result)
                    Toast.makeText(context, "Unable to connect. Please use a valid adress", Toast.LENGTH_SHORT).show();
                else {
                    Toast.makeText(getApplicationContext(), "Connected to : " + edit_ip.getText().toString(), Toast.LENGTH_LONG).show();
                    Intent i = new Intent(context, ControlActivity.class);
                    i.putExtra(ConnectService.IPSERV, edit_ip.getText().toString());
                    startActivity(i);
                }
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        Button connect = (Button) findViewById(R.id.connect_btn);
        Button github = (Button) findViewById(R.id.github_btn);
        Button info = (Button) findViewById(R.id.info_btn);
        edit_ip = (EditText) findViewById(R.id.input_btn);
        registerReceiver(receiver, new IntentFilter("com.ehmanu.rtcompanionjpo"));
        github.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Uri git = Uri.parse("https://github.com/chambo-e/Raytracer_Android_App");
                String title = getResources().getString(R.string.open_web);
                Intent webIntent = new Intent(Intent.ACTION_VIEW, git);
                Intent chooser = Intent.createChooser(webIntent, title);
                if (webIntent.resolveActivity(getPackageManager()) != null) {
                    startActivity(chooser);
                }
            }
        });
        info.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Uri git = Uri.parse("http://www.epitech.eu/blogs/raytracer-pauv-ray-projet-epitech-1-art68.html");
                String title = getResources().getString(R.string.open_web);
                Intent webIntent = new Intent(Intent.ACTION_VIEW, git);
                Intent chooser = Intent.createChooser(webIntent, title);
                if (webIntent.resolveActivity(getPackageManager()) != null) {
                    startActivity(chooser);
                }
            }
        });
        connect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (edit_ip.getText().toString().isEmpty())
                    return;
                Intent i = new Intent(LoginActivity.this, ConnectService.class);
                i.putExtra(ConnectService.IPSERV, edit_ip.getText().toString());
                startService(i);
            }
        });
    }

    protected void onResume() {
        super.onResume();
        registerReceiver(receiver, new IntentFilter("com.ehmanu.rtcompanionjpo"));
    }

    protected void onPause() {
        super.onPause();
        unregisterReceiver(receiver);
    }
}
