package com.ehmanu.rtcompanionjpo;

import android.app.IntentService;
import android.app.Service;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.IBinder;

import java.net.Socket;

/**
 * Created by Manu on 27/06/2014.
 */
public class ConnectService extends IntentService {

    public static final String RESPONSE = "response";
    public static final String IPSERV = "ipserv";
    private static final String TAG = "ConnectService";
    private static Socket sock = null;
    private final static int PORT = 7879;

    public ConnectService() {
        super("ConnectService");
    }

    @Override
    protected void onHandleIntent(Intent intent) {

    }
}
