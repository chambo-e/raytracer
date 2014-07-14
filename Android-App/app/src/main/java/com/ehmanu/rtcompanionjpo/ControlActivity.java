package com.ehmanu.rtcompanionjpo;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.MenuItem;
import android.support.v4.app.FragmentActivity;
import android.view.Window;

public class ControlActivity extends FragmentActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_INDETERMINATE_PROGRESS);
        setContentView(R.layout.activity_control);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                ConnectService.close_socket();
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onBackPressed() {
        show_alert();
    }

    private void show_alert() {
        AlertDialog.Builder alert = new AlertDialog.Builder(this);
        alert.setTitle("Close Connection ?");
        alert
                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        ConnectService.close_socket();
                        finish();
                    }
                })
                .setNegativeButton("No", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                })
                .show();
    }
}
