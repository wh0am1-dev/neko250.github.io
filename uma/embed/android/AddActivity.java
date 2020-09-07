package dev.wh0am1.test;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class AddActivity extends AppCompatActivity {
    private Agenda agenda;

    private EditText inName;
    private EditText inNumber;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add);

        agenda = (Agenda) Global.getInstance().get(MainActivity.AGENDA);

        inName = findViewById(R.id.inName);
        inNumber = findViewById(R.id.inNumber);

        Button btnOk = findViewById(R.id.btnOk);
        btnOk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setResult(Activity.RESULT_CANCELED);

                if (agenda.contacts().upsert(inName.getText().toString(), inNumber.getText().toString()) != null) {
                    setResult(Activity.RESULT_OK);
                }

                finish();
            }
        });

        Button btnCancel = findViewById(R.id.btnCancel);
        btnCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setResult(Activity.RESULT_CANCELED);
                finish();
            }
        });
    }
}
