package dev.wh0am1.test;

import android.app.Activity;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class Agenda extends SQLiteOpenHelper {
    private static final String DB_NAME = "AgendaDB";
    private static final int VERSION = 1;

    private final ContactDAO contacts;

    public Agenda(Activity activity) {
        super(activity.getApplicationContext(), DB_NAME, null, VERSION);
        contacts = new ContactDAO(this);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(Contact.SQL_CREATE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
    }

    public ContactDAO contacts() {
        return contacts;
    }
}
