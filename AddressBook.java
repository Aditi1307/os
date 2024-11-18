
import java.util.ArrayList;
import java.util.Scanner;

class Record {
    String name;
    String phone;
    String email;

    Record(String name, String phone, String email) {
        this.name = name;
        this.phone = phone;
        this.email = email;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Phone: " + phone + ", Email: " + email;
    }
}

public class AddressBook {
    private ArrayList<Record> addressBook = new ArrayList<>();
    private Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        AddressBook addressBook = new AddressBook();
        addressBook.run();
    }

    public void run() {
        while (true) {
            System.out.println("\nAddress Book Menu:");
            System.out.println("a) Create address book");
            System.out.println("b) View address book");
            System.out.println("c) Insert a record");
            System.out.println("d) Delete a record");
            System.out.println("e) Modify a record");
            System.out.println("f) Exit");
            System.out.print("Choose an option: ");
            String choice = scanner.nextLine().toLowerCase();

            switch (choice) {
                case "a":
                    createAddressBook();
                    break;
                case "b":
                    viewAddressBook();
                    break;
                case "c":
                    insertRecord();
                    break;
                case "d":
                    deleteRecord();
                    break;
                case "e":
                    modifyRecord();
                    break;
                case "f":
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid option. Please choose again.");
            }
        }
    }

    private void createAddressBook() {
        addressBook.clear();
        System.out.println("Address book created successfully.");
    }

    private void viewAddressBook() {
        if (addressBook.isEmpty()) {
            System.out.println("Address book is empty.");
        } else {
            System.out.println("\nAddress Book:");
            for (int i = 0; i < addressBook.size(); i++) {
                System.out.println((i + 1) + ". " + addressBook.get(i));
            }
        }
    }

    private void insertRecord() {
        System.out.print("Enter name: ");
        String name = scanner.nextLine();
        System.out.print("Enter phone number: ");
        String phone = scanner.nextLine();
        System.out.print("Enter email: ");
        String email = scanner.nextLine();

        addressBook.add(new Record(name, phone, email));
        System.out.println("Record added successfully.");
    }

    private void deleteRecord() {
        viewAddressBook();
        if (addressBook.isEmpty())
            return;

        System.out.print("Enter the record number to delete: ");
        try {
            int recordNumber = Integer.parseInt(scanner.nextLine());
            if (recordNumber > 0 && recordNumber <= addressBook.size()) {
                Record removed = addressBook.remove(recordNumber - 1);
                System.out.println("Record '" + removed.name + "' deleted successfully.");
            } else {
                System.out.println("Invalid record number.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Please enter a valid number.");
        }
    }

    private void modifyRecord() {
        viewAddressBook();
        if (addressBook.isEmpty())
            return;

        System.out.print("Enter the record number to modify: ");
        try {
            int recordNumber = Integer.parseInt(scanner.nextLine());
            if (recordNumber > 0 && recordNumber <= addressBook.size()) {
                Record record = addressBook.get(recordNumber - 1);

                System.out.print("Enter new name (leave empty to keep current): ");
                String newName = scanner.nextLine();
                if (!newName.isEmpty())
                    record.name = newName;

                System.out.print("Enter new phone number (leave empty to keep current): ");
                String newPhone = scanner.nextLine();
                if (!newPhone.isEmpty())
                    record.phone = newPhone;

                System.out.print("Enter new email (leave empty to keep current): ");
                String newEmail = scanner.nextLine();
                if (!newEmail.isEmpty())
                    record.email = newEmail;

                System.out.println("Record modified successfully.");
            } else {
                System.out.println("Invalid record number.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Please enter a valid number.");
        }
    }
}
