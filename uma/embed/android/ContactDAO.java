package dev.wh0am1.test;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;
import java.util.List;

public class ContactDAO {
    private Agenda agenda;

    public ContactDAO(Agenda agenda) {
        this.agenda = agenda;
    }

    public List<Contact> all() {
        SQLiteDatabase db = agenda.getReadableDatabase();
        Cursor cur = db.query(Contact.TABLE, null, null, null, null, null, Contact.COL_NAME);
        List<Contact> contacts = cursorToList(cur);
        cur.close();
        db.close();
        return contacts;
    }

    public List<Contact> fuzzySearch(String filter) {
        SQLiteDatabase db = agenda.getReadableDatabase();
        String _filter = "%" + filter.toLowerCase() + "%";
        Cursor cur = db.query(Contact.TABLE, null, "lower(" + Contact.COL_NAME + ") like ? or " + Contact.COL_NUMBER + " like ?", new String[]{_filter, _filter}, null, null, Contact.COL_NAME);
        List<Contact> contacts = cursorToList(cur);
        cur.close();
        db.close();
        return contacts;
    }

    public Contact search(String name) {
        SQLiteDatabase db = agenda.getReadableDatabase();
        Cursor cur = db.query(Contact.TABLE, null, "lower(" + Contact.COL_NAME + ") = ?", new String[]{name.toLowerCase()}, null, null, Contact.COL_NAME);
        List<Contact> results = cursorToList(cur);
        cur.close();
        db.close();

        if (results.size() > 0) return results.get(0);
        return null;
    }

    public Contact upsert(String name, String number) {
        Contact contact = search(name);
        SQLiteDatabase db = agenda.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put(Contact.COL_NAME, name);
        cv.put(Contact.COL_NUMBER, number);

        if (contact == null) {
            db.insert(Contact.TABLE, null, cv);
        } else {
            db.update(Contact.TABLE, cv, Contact.COL_NAME + " = ?", new String[]{name});
        }

        db.close();
        return search(name);
    }

    private List<Contact> cursorToList(Cursor cur) {
        List<Contact> contacts = new ArrayList<>();

        if (cur.moveToFirst()) {
            do {
                Contact c = new Contact();
                c.setName(cur.getString(cur.getColumnIndex(Contact.COL_NAME)));
                c.setNumber(cur.getString(cur.getColumnIndex(Contact.COL_NUMBER)));
                contacts.add(c);
            } while (cur.moveToNext());
        }

        return contacts;
    }
}
