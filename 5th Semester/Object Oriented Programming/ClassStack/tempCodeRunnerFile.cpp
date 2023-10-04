bool running = true;
    int operation = 0; 
    while(running)
    {
        cout << "=================================\n"
        << "Welcome! Available functions are:\n"
        << "=================================\n"
        << "1. Push\n"
        << "2. Top\n"
        << "3. Pop\n"
        << "4. Show\n"
        << "5. Terminate the programm\n"
        << "=================================\n"
        << "Choose an operation: ";
        cin >> operation;
        switch (operation)
        {
            case 1:
                cout << "Enter an index and a value to add: "; 
                double Value; cin >> Value;
                Container.push(Value);
                Container.show(); 
                break;
            case 2:
                Container.top();
                break;
            case 3:
                Container.pop();
                Container.show();
                break;
            case 4:
                Container.show();
                break;
            case 5:
                cout << "Terminating the program...";
                running = false;
                exit(0);
            default: cout << "Invalid option. Please, try again." << '\n';
        }
    }