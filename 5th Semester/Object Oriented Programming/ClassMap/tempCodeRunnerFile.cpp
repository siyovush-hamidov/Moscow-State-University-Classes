
    // bool running = true;
    // int operation = 0; 
    // while(running)
    // {
    //     cout << "=================================\nWelcome!\n=================================\n1. Get the quantity of elements\n2. Find an element by key\n3. Find an element by value\n4. Refresh indexes\n5. Insert an element\n6. Delete an element by index\n7. Sort the map\n8. Save to file\n9. Print the map\n10. Exit the program\n=================================\nChoose an operation: "; 
    //     cin >> operation;

    //     switch (operation)
    //     {
    //         case 1:
    //         {
    //             int quan = map.count();
    //             cout <<"The quantity is: " << quan << '\n';
    //             break;
    //         }
    //         case 2:
    //         {
    //             int key;
    //             string value;
    //             cout << "Enter the key to search for: ";
    //             cin >> key;
    //             value = map.find(key);
    //             cout << value << " was found."<< '\n';
    //             break;
    //         }
    //         case 3:
    //         {
    //             cin.ignore();
    //             int key;
    //             string value;
    //             cout << "Enter the value to search for: ";
    //             getline(cin, value);
    //             key = map.find(value);
    //             cout << key << " was found." << '\n';
    //             break;
    //         }
    //         case 4:
    //         {
    //             map.refresh_indexes();
    //             map.show();
    //             break;
    //         }
    //         case 5:
    //         {
    //             int k; string v;
    //             cout << "Enter the key to insert: ";
    //             cin >> k;
    //             cout << "Enter the value to insert: ";
    //             cin.ignore();
    //             getline(cin, v);
    //             if(map.if_key_is_present(k))
    //             {
    //                 cout << "The key is already in use, so the element's value will be altered.\n";
    //             }
    //             map.insert(k, v);
    //             map.show();
    //             break;
    //         }
    //         case 6:
    //         {
    //             int index_to_delete;
    //             cout << "Enter the index to delete: ";
    //             cin >> index_to_delete;
    //             map.delete_element(index_to_delete);
    //             map.show();
    //             break;
    //         }
    //         case 7:
    //         {
    //             map.sort_map();
    //             map.show();
    //             break;
    //         }
    //         case 8: 
    //         {
    //             map.save_to_file();
    //             break;
    //         }
    //         case 9:
    //         {
    //             map.show();
    //             break;
    //         }
    //         case 10:
    //         {
    //             cout << "Terminating the program..."; 
    //             running = false;
    //             exit(0);
    //         }
    //         default: cout << "Invalid option. Please, try again." << std::endl;
    //     }
    // }
    // return 0;