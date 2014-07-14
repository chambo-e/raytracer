package com.ehmanu.rtcompanionjpo;

import android.app.IntentService;
import android.content.Intent;
import android.os.AsyncTask;
import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.Enumeration;
import java.util.concurrent.ExecutionException;

/**
 * * Created by chambo_e on 6/27/14.
 */
public class ConnectService extends IntentService {

    public static final String RESPONSE = "response";
    public static final String IPSERV = "ipserv";
    private final static int PORT = 7879;
    private static Socket sock = null;

    public ConnectService() {
        super("ConnectService");
    }

    @Override
    protected void onHandleIntent(Intent intent) {
        boolean error = false;
        String addr = intent.getStringExtra(IPSERV);
        try {
            sock = new Socket(addr, PORT);
        } catch (IOException e) {
            e.printStackTrace();
            error = true;
        }
        handleBroadcast(error);
    }

    private void handleBroadcast(boolean error) {
        Intent i = new Intent("com.ehmanu.rtcompanionjpo");
        i.putExtra(RESPONSE, error);
        sendBroadcast(i);
    }

    public static void close_socket() {
        try {
            sock.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static String get_name_server() {
        return sock.getInetAddress().toString();
    }

    public boolean ask_aa() {
        String result = null;
        try {
            send_data("ASKAA;" + getIpAddress() + "*");
            result = new GetInput().execute().get();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }
        return result != null && result.equals("ASKAA=OK");
    }

    public String ask_obj() {
        String re = null;
        try {
            send_data("ASKOBJ;" + getIpAddress() + "*");
            re = new GetInput().execute().get();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }
        return re;
    }

    public String ask_spot() {
        String re = null;
        try {
            send_data("ASKSPOT;" + getIpAddress() + "*");
            re = new GetInput().execute().get();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }
        return re;
    }

    public static void send_data(String pattern) {
        OutputStream outputStream;
        PrintStream printStream;

        try {
            outputStream = sock.getOutputStream();
            printStream = new PrintStream(outputStream);
            printStream.print(pattern);
            printStream.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String getIpAddress() {
        String ip = "";
        try {
            Enumeration<NetworkInterface> enumNetworkInterfaces = NetworkInterface.getNetworkInterfaces();
            while (enumNetworkInterfaces.hasMoreElements()) {
                NetworkInterface networkInterface = enumNetworkInterfaces
                        .nextElement();
                Enumeration<InetAddress> enumInetAddress = networkInterface
                        .getInetAddresses();
                while (enumInetAddress.hasMoreElements()) {
                    InetAddress inetAddress = enumInetAddress.nextElement();

                    if (inetAddress.isSiteLocalAddress()) {
                        ip += inetAddress.getHostAddress();
                    }
                }
            }
        } catch (SocketException e) {
            e.printStackTrace();
        }
        return ip;
    }

    private class GetInput extends AsyncTask<Void, Void, String> {
        @Override
        protected String doInBackground(Void... params) {
            ServerSocket ss = null;
            try {
                ss = new ServerSocket(7879);
            } catch (IOException e) {
                e.printStackTrace();
            }
            String income = null;
            Socket s = null;
            try {
                if (ss != null) {
                    s = ss.accept();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            BufferedReader input = null;
            try {
                if (s != null) {
                    input = new BufferedReader(new InputStreamReader(s.getInputStream()));
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                if (input != null) {
                    income = input.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                if (s != null) {
                    s.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                if (ss != null) {
                    ss.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return income;
        }
    }
}