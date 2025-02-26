Hotel::Hotel()
{
    counter1 = 0, counter2 = 0;
    room_managment();
}
void Hotel::room_managment()
{
    int number;
    for (int i = 0; i <= 20; i++)
    {
        rooms[i] = emtpy_room;
    }
    do
    {
        cout << "\t ------ Otel Mesaji----\n";
        cout << "\t1. Oda Rezervasiya\n";
        cout << "\t2. Oda Bosaltma\n ";
        cout << "\t3. Dolu Oda Sayisi\n";
        cout << "\t4. Oda Reportu\n";
        cout << "\t5. Toplam gelir\n";
        cout << "\t6. Cixis Et\n";
        cout << "\tSecimini Gir: ";
        cin >> number;
        switch (number)
        {
        case 1:
            room_reservation();
            break;
        case 2:
            room_evacuation();
            break;
        case 3:
            number_of_customers();
            break;
        case 4:
            room_report();
            break;
        case 5:
            income();
            break;
        case 6:
            memory();
            exit(1);
            break;
        default:
            cout << "Duzgun Secim Edilmedi";
            break;
        }
    } while (number != 6);
}
void Hotel::room_reservation()
{
    int number, numberOfDays, i = 1, j = 13;
    string name, lastname;
    cout << "\n\t Otaq tipi secin\n";
    cout << "\t1. Tek Adamliq\n";
    cout << "\t2. Iki Neferlik\n";
    cout << "Secimi Daxil edin: ";
    cin >> number;
    switch (number)
    {
    case 1:
        for (; i <= 12; i++)
        {
            if (rooms[i] != full_room)
            {
                rooms[i] = full_room;
                cout << "Adiniz: ";
                cin >> name;
                cout << "Soyadiniz: ";
                cin >> lastname;
                cout << "Nece gun Qalacaqsiz: ";
                cin >> numberOfDays;
                sum += numberOfDays * 600;
                counter1++;
                customer_name[i] = new string;
                *customer_name[i] = name;
                customer_lastname[i] = new string;
                *customer_lastname[i] = lastname;
                break;
            }
        }
        if (i == 12)
        {
            cout << "Tek Adamliq otaqlar Doldu\n";
        }
        break;
    case 2:
        for (; j <= 20; j++)
        {
            if (rooms[j] != full_room)
            {
                rooms[j] = full_room;
                cout << "Adiniz: ";
                cin >> name;
                cout << "Soyadiniz: ";
                cin >> lastname;
                cout << "Nece gun Qalacaqsiz: ";
                cin >> numberOfDays; //Burada istifadecinin girisini yoxlamaq lazimdi 
                sum += numberOfDays * 1000;
                counter2++;
                customer_name[j] = new string;
                *customer_name[j] = name;
                customer_lastname[j] = new string;
                *customer_lastname[j] = lastname;
                break;
            }
        }
        if (i == 20)
        {
            cout << "Iki Adamliq otaqlar Doldu\n";
        }
        break;
    default:
        cout << "Oda Secimi Yalnisdir! \n";
        break;
    }
}
void Hotel::room_evacuation()
{
    int number;
    cout << "Hansi otagi Bosalir: ";
    cin >> number;
    if (rooms[number] == full_room)
    {
        rooms[number] = emtpy_room;
        delete customer_lastname[number];
        delete customer_name[number];
        if (number > 0 && number <= 12)
        {
            counter1--;
        }
        else if (number <= 13 && number <= 20)
        {
            counter2--;
        }
        cout << "Otaq Bosaltildi\n";
    }
    else if (number <= 0 || number > 20)
    {
        cout << "Bele Otaq movcud deyil\n";
        room_evacuation();
    }
    else
    {
        cout << "Bu otaq zaten bosdur\n";
    }
}
void Hotel::room_report()
{
    if (counter1 == 0 && counter2 == 0)
    {
        cout << "Butun otaqlar Bosdur" << "\n";
    }
    else
    {
        cout << "Otaq Nomresi Musteri adi ve Soyadi\n=================================\n";
        for (int i = 0; i < 20; i++)
        {
            if (rooms[i] == full_room)
            {
                cout << "Nomre: " << i << "\tAd: " << *customer_name[i]<<"       " << "\tSoyad: " << *customer_lastname[i] << "\n";
            }
        }
        cout << "=================================\n";
    }
}
void Hotel::income()
{
    cout << "Toplam Gelir: " << sum << "\n";
}
void Hotel::number_of_customers()
{
    cout << "Dolu Olan Ikineferlik Otaqlar " << counter2 << "\n";
    cout << "Dolu Olan Birneferlik Otaqlar " << counter1 << "\n";
}
void Hotel::memory()
{
    for (int i = 0; i < 20; i++)
    {
        delete customer_lastname[i];
        delete customer_lastname[i];
    }
}