package dev.wh0am1.test;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.TypedValue;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    public static final String AGENDA = "AGENDA";

    private Agenda agenda;
    private List<Contact> contacts;

    private EditText inSearch;
    private ArrayAdapter<Contact> contactListAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        agenda = new Agenda(this);
        Global.getInstance().put(AGENDA, agenda);

        inSearch = findViewById(R.id.inSearch);
        contacts = new ArrayList<>(agenda.contacts().fuzzySearch(inSearch.getText().toString()));

        Button btnSearch = findViewById(R.id.btnSearch);
        btnSearch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                List<Contact> results = agenda.contacts().fuzzySearch(inSearch.getText().toString());
                contacts.clear();
                contacts.addAll(results);
                contactListAdapter.notifyDataSetChanged();

                if (results.size() == 0) {
                    Toast.makeText(MainActivity.this, "", Toast.LENGTH_SHORT).show();
                }
            }
        });

        Button btnAdd = findViewById(R.id.btnAdd);
        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent addIntent = new Intent(MainActivity.this, AddActivity.class);
                startActivityForResult(addIntent, 1337);
            }
        });

        contactListAdapter = new ArrayAdapter<Contact>(this, android.R.layout.simple_list_item_1, contacts) {
            @NonNull
            @Override
            public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
                View view = super.getView(position, convertView, parent);
                TextView text = view.findViewById(android.R.id.text1);
                text.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 20);
                return view;
            }
        };

        ListView contactList = findViewById(R.id.contactList);
        contactList.setAdapter(contactListAdapter);
        contactList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int pos, long id) {
                Intent phoneIntent = new Intent(Intent.ACTION_DIAL).setData(Uri.parse("tel:" + contactListAdapter.getItem(pos).getNumber()));
                startActivity(phoneIntent);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if (requestCode == 1337 && resultCode == Activity.RESULT_OK) {
            Toast.makeText(this, R.string.toast_added, Toast.LENGTH_SHORT).show();
            inSearch.setText("");
            contacts.clear();
            contacts.addAll(agenda.contacts().all());
            contactListAdapter.notifyDataSetChanged();
        }

        super.onActivityResult(requestCode, resultCode, data);
    }

    private void mock(Agenda agenda) {
        agenda.contacts().upsert("Carlos Aguilar", "12345678");
        agenda.contacts().upsert("John Gomm", "12345678");
        agenda.contacts().upsert("Alan Watts", "12345678");
        agenda.contacts().upsert("Dieter Rams", "12345678");
        agenda.contacts().upsert("Dam Rass", "12345678");
    }
}
