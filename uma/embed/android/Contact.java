package dev.wh0am1.test;

import androidx.annotation.NonNull;

public class Contact {
    public static final String TABLE = "Contact";
    public static final String COL_NAME = "name";
    public static final String COL_NUMBER = "number";
    public static final String SQL_CREATE = String.format("create table %s (%s text primary key, %s text not null);", TABLE, COL_NAME, COL_NUMBER);

    private String name;
    private String number;

    public Contact() {}

    public Contact(String name, String number) {
        this.name = name;
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Contact contact = (Contact) o;
        return name.equalsIgnoreCase(contact.name) &&
                number.equalsIgnoreCase(contact.number);
    }

    @NonNull
    @Override
    public String toString() {
        return String.format("%s (%s)", name, number);
    }
}
