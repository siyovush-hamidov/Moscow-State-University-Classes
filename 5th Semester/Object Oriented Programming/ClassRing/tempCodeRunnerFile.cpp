, V value)
    // {
    //     while (if_index_already_is_present(index))
    //     {
    //         std ::cout << "Please, enter the index once more: ";
    //         std ::cin >> index;
    //     }

    //     List *NewRecord = new List;

    //     NewRecord->Index = index;
    //     NewRecord->Value = value;
    //     List *temp = PointerToLast;
    //     for (int i = 0; i < N; i++)
    //     {
    //         NewRecord->PointerToNext = temp;
    //         temp = temp->PointerToPrevious;
    //     }
    //     NewRecord->PointerToPrevious = PointerToLast;

    //     if (PointerToLast == nullptr)
    //     {
    //         NewRecord->PointerToPrevious = NewRecord;
    //         NewRecord->PointerToNext = NewRecord;
    //         PointerToLast = NewRecord;
    //     }
    //     else
    //     {
    //         NewRecord->PointerToPrevious = PointerToLast;
    //         PointerToLast->PointerToNext = NewRecord;
    //         PointerToLast = NewRecord;
    //     }
    //     N++;
    //     std ::cout << "The element was added to the end successfully.\n";
    // }