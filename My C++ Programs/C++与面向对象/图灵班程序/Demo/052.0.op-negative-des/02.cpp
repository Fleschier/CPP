enum direction { Login = 1, Logout = 0 };

class tracking
{
    static int sum;
    static int max;
    int number;
public:
    tracking();
    ~tracking();
    void report( int );
};

int tracking::sum = 0;
int tracking::max = 0;

tracking::tracking()
{
    number = ++max;
    sum++;
    report( Login );
}

tracking::~tracking()
{
    sum--;
    report( Logout );
}

void tracking::report( int dir )
{
    cout << "Object No." << number << ( ( dir ) ? "\tcreated. " : "\tremoved. " );
    cout << "Totally " << sum << " object(s) " << "available" << endl;
}
