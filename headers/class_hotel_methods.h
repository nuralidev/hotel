Hotel::Hotel()
{
    counter1 = 0, counter2 = 0;
    for (int i = 0; i < 20; i++)
    {
        rooms[i] = emtpy_room;
        customer_name[i] = nullptr;
        customer_lastname[i] = nullptr;
    }

    room_managment();
}
void Hotel::room_managment()
{
    int number;
    for (int i = 0; i < 20; i++)
    {
        rooms[i] = emtpy_room;
    }
    do
    {
        cout << "------ Otel Mesaji----\n";
        cout << "1. Otaq Rezervasiya\n";
        cout << "2. Otaq Bosaltma\n";
        cout << "3. Dolu Oda Sayi\n";
        cout << "4. Otaq Reportu\n";
        cout << "5. Toplam gelir\n";
        cout << "6. Cixis Et\n";
        checkInput("Secimini Gir", number);
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
            return ;
            break;
        default:
            cout << RED<<"Duzgun Secim Edilmedi\n"<<RESET;
            break;
        }
    } while (number != 6);
}
void Hotel::room_reservation()
{
    int number, numberOfDays, i = 1, j = 13;
    string name, lastname;
    cout << " \nOtaq tipi secin\n";
    cout << "1. Tek Adamliq\n";
    cout << "2. Iki Neferlik\n";
    cout << "\nSecimi Daxil edin: ";
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
                checkInput("Nece gun Qalacaqsiz", numberOfDays);
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
                checkInput("Nece gun Qalacaqsiz: ", numberOfDays);
                sum += numberOfDays * 1000;
                counter2++;
                customer_name[j] = new string;
                *customer_name[j] = name;
                customer_lastname[j] = new string;
                *customer_lastname[j] = lastname;
                break;
            }
        }
        if (j == 20)
        {
            cout <<"Iki Adamliq otaqlar Doldu\n";
        }
        break;
    default:
        cout << RED<<"Otaq Secimi Yalnisdir! \n"<<RESET;
        cin.clear();
        cin.ignore(256, '\n');
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
    else if (number <1 || number > 20)
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
                cout << "Nomre: " << i << "\tAd: " << *customer_name[i] << "       " << "\tSoyad: " << *customer_lastname[i] << "\n";
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
        if(customer_lastname[i]!=nullptr){

            delete customer_lastname[i];
            customer_lastname[i]=nullptr;
        }
        if(customer_name[i]!=nullptr){

            delete customer_name[i];
            customer_name[i]=nullptr;
        }
 
    }
    cout<<"Yaddas temizlendi";
}
void Hotel::checkInput(string sablonMesaj, int &checkObject)
{
    string giris;
    cout << sablonMesaj << ": ";
    cin >> giris;
    while (!isNumber(giris))
    {
        cout << RED<<"Zehmet olmasa eded daxil edin\n"<<RESET;
        cin.clear();
        cin.ignore(256, '\n');
        cout << sablonMesaj << ": ";
        cin >> giris;
    }
    checkObject = stoi(giris);
}
bool Hotel::isNumber(const string s)
{
    if (s.empty())
    {
        return false;
    }
    for (char c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
Hotel::~Hotel() {
    memory(); 
}