package dev.wh0am1.test;

import java.util.HashMap;

public class Global {
    private static HashMap<String, Object> instance;

    private Global() {}

    public static HashMap<String, Object> getInstance() {
        if (instance == null) instance = new HashMap<>();
        return instance;
    }
}
