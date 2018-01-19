// package
import com.google.appengine.api.datastore.*;

// dir: war/WEB-INF/local_db.bin
public class AppEngine {
  public static String name;
  public static String phone;
  public static String date;
  
  public static void samples() {
    // entities
    Entity e = new Entity("User");
    Key key = e.getKey;
    e.setProperty("date", "24");
    date = e.getProperty("date");
    // service
    DatastoreService ds = DatastoreServiceFactory.getDatastoreService();
    key = ds.put(e);
    e = ds.get(key);
    ds.delete(key);
    // transactions
    Transaction t = ds.beginTransaction();
    key = ds.put(t, e);
    e = ds.get(t, key);
    ds.delete(t, key);
    t.commit();
    t.rollback();
    // queries
    Query query = new Query("User").addSort("name", Query.SortDirection.ASCENDING);
    List<Entity> entities = ds.prepare(query).asList(FetchOptions.Builder.withLimit(20));
    List<User> users = new ArrayList<>();
    for (Entity e : entities) {
      name = e.getProperty("name");
      phone = e.getProperty("phone");
      date = e.getProperty("date");
      users.add(new User(name, phone, date));
    }
  }
}
