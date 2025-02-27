class Hotel{
    private:
    std::string* customer_name[100],*customer_lastname[100];
    int sum=0,counter1,counter2;
    enum status{
        emtpy_room,
        full_room
    }rooms[20];
    public:
    Hotel();
    ~Hotel();
    void room_managment();
    void room_reservation();
    void room_evacuation();
    void number_of_customers();
    void room_report();
    void income();
    void memory();
    void checkInput(string,int &);
    bool isNumber(const string);
};