#include <iostream>
#include<string>
using namespace std;

struct City
{
    int area_code;
    string name;
    string abbreviation;
    long population;
    double surface_area;

};

//1-Functions prototypes；Function declarations
void add_cities(City cities_array[], const int MAX);
void print_cities(City cities_array[], const int MAX);
void search_cities_code(City cities_array[], const int MAX, int id);
void search_cities_name(City cities_array[], const int MAX, string key);
void print_element(City cities_array[], int position);
int find_highest_area(City cities_array[], const int MAX);
void sort_cities(City cities_array[], const int MAX);
//2-Main application

int main()
{
    const int MAX = 3;
    City cities_array[MAX];
    int option, id;
    int keep_looping;
    int position;
    string key;



    cout << "\n\t\t\t\t ****************\n ";
    cout << "\t\t\t\t  ***** MENU *****\t\t\t ";
    cout << "\n\t\t\t\t **************** \n";
    do
    {
        cout << "MENU OPTIONS :\n\t< 1 . ADD Cities >\n\t< 2 . PRINT Cities >\n\t< 3. SEARCH FOR A City BY Code Area >\n\t< 4. SEARCH BY NAME>\n\t< 5. Find The City Having The Highest Surface Area>\n\t< 6. Order The Cities Array By Surface Area>" << endl;
        cout << " ENTER YOUR CHOICE: ";
        cin >> option;
        switch (option)
        {
        case 1:
            add_cities(cities_array, MAX);
            break;

        case 2:
            print_cities(cities_array, MAX);
            break;

        case 3:
            cout << "\n SEARCH FOR A City BY Code Area: ";
            cout << "\n ENTER The Code: ";
            cin >> id;
            search_cities_code(cities_array, MAX, id);
            break;

        case 4:
            cout << "\n SEARCH FOR A City BY NAME: ";
            cout << "\n ENTER NAME: ";
            cin >> key;
            search_cities_name(cities_array,  MAX,  key);
            break;

        case 5:
            cout << "\n FIND THE CITY HAVING THE HIGHEST SURFACE AREA";
            position=find_highest_area(cities_array, MAX);
            print_element(cities_array, position);
            break;

        case 6:
            cout << "\n Order The Cities Array By Surface Area" << endl;
            sort_cities(cities_array, MAX);
            print_cities(cities_array, MAX);
            break;

        default:
            cout << "\n\t\t\t Invalid input(you MUST input (1-6)\n";
            break;
        }
        cout << "\n\t\t\t Do you want to continue? \n\t\t\t [type 1 (for yes) - type 0 (for no)]: ";
        cin >> keep_looping;
    } while (keep_looping == 1);
    cout << "\n This application written by Jiarui Li-2014570" << endl;
    system("pause");
    return 0;
}


//3-Functions implementations
void add_cities(City cities_array[], const int MAX)
{
    cout << "\n Add cities into the city array....\n";
    for (int index = 0; index < MAX; index++)
    {
        cout << "\n ***************************" << endl;
        cout << "\n City name:";
        cin >> cities_array[index].name;
        cout << "\n City Code Area:";
        cin >> cities_array[index].area_code;
        cout << "\n City Abbreviation:";
        cin >> cities_array[index].abbreviation;
        cout << "\n City Population:";
        cin >> cities_array[index].population;
        cout << "\n City Surface Area:";
        cin >> cities_array[index].surface_area;

    }
}
void print_cities(City cities_array[], const int MAX)
{
    cout << "List of Cities" << endl;
    for (int index = 0; index < MAX; index++)
    {
        cout << "City Name：" << cities_array[index].name << endl;
        cout << "City Code Area：" << cities_array[index].area_code << endl;
        cout << "City Abbreviation：" << cities_array[index].abbreviation << endl;
        cout << "City Population：" << cities_array[index].population << endl;
        cout << "City Surface Area：" << cities_array[index].surface_area << endl;
        cout << "--------------------------------------------" << endl;
    }
}
void search_cities_code(City cities_array[], const int MAX, int id)
{
    int position=-1;
    for (int index=0;index<MAX;index++)
    {
        if (cities_array[index].area_code == id)
        {
            position = index;
            break;
        }
    }
    print_element(cities_array, position);
}
void search_cities_name(City cities_array[], const int MAX, string key)
{
    int position= -1;
    for (int index = 0; index < MAX; index++)
    {
        if (cities_array[index].name == key)
        {
            position = index;
            break;
        }
    }
    print_element(cities_array, position);
}

void print_element(City cities_array[], int position)
{
    if (position == -1)
    {
        cout << "City NOT FOUND..." << endl;
    }
    else
    {
        cout << "                " << endl;
        cout << "City Name：" << cities_array[position].name << endl;
        cout << "City Code Area：" << cities_array[position].area_code << endl;
        cout << "City Abbreviation：" << cities_array[position].abbreviation << endl;
        cout << "City Population：" << cities_array[position].population << endl;
        cout << "City Surface Area：" << cities_array[position].surface_area << endl;
    }
}
int find_highest_area(City cities_array[], const int MAX)
{
    int position=-1;
    City highest_city = cities_array[0];
    for (int index = 0; index < MAX; index++)
    {
        if (cities_array[index].surface_area > highest_city.surface_area)
        {
            highest_city = cities_array[index];
            position = index;
        }
    }
    return position;
}
void sort_cities(City cities_array[],const int MAX)
{
    cout << "\n Order Cities by Surface Area(using reference)\n";
    for (int index1 = 0; index1 < MAX; index1++)
    {
        for (int index2 = index1 + 1; index2 < MAX; index2++)
        {
            if (cities_array[index1].surface_area > cities_array[index2].surface_area)
            {
                City temporary_cities;
                temporary_cities = cities_array[index1];
                cities_array[index1] = cities_array[index2];
                cities_array[index2] = temporary_cities;
            }
        }
    }
}

/*

                                 ****************
                                  ***** MENU *****
                                 ****************
MENU OPTIONS :
        < 1 . ADD Cities >
        < 2 . PRINT Cities >
        < 3. SEARCH FOR A City BY Code Area >
        < 4. SEARCH BY NAME>
        < 5. Find The City Having The Highest Surface Area>
        < 6. Order The Cities Array By Surface Area>
 ENTER YOUR CHOICE: 1

 Add cities into the city array....

 ***************************

 City name:Montreal

 City Code Area:514

 City Abbreviation:YUL

 City Population:1780000

 City Surface Area:431.5

 ***************************

 City name:Toronto

 City Code Area:416

 City Abbreviation:YYZ

 City Population:2790060

 City Surface Area:630.2

 ***************************

 City name:Vancouver

 City Code Area:604

 City Abbreviation:YVR

 City Population:2463431

 City Surface Area:114.97

                         Do you want to continue?
                         [type 1 (for yes) - type 0 (for no)]: 1
MENU OPTIONS :
        < 1 . ADD Cities >
        < 2 . PRINT Cities >
        < 3. SEARCH FOR A City BY Code Area >
        < 4. SEARCH BY NAME>
        < 5. Find The City Having The Highest Surface Area>
        < 6. Order The Cities Array By Surface Area>
 ENTER YOUR CHOICE: 2
List of Cities
City Name：Montreal
City Code Area：514
City Abbreviation：YUL
City Population：1780000
City Surface Area：431.5
--------------------------------------------
City Name：Toronto
City Code Area：416
City Abbreviation：YYZ
City Population：2790060
City Surface Area：630.2
--------------------------------------------
City Name：Vancouver
City Code Area：604
City Abbreviation：YVR
City Population：2463431
City Surface Area：114.97
--------------------------------------------

                         Do you want to continue?
                         [type 1 (for yes) - type 0 (for no)]: 1
MENU OPTIONS :
        < 1 . ADD Cities >
        < 2 . PRINT Cities >
        < 3. SEARCH FOR A City BY Code Area >
        < 4. SEARCH BY NAME>
        < 5. Find The City Having The Highest Surface Area>
        < 6. Order The Cities Array By Surface Area>
 ENTER YOUR CHOICE: 3

 SEARCH FOR A City BY Code Area:
 ENTER The Code: 416

City Name：Toronto
City Code Area：416
City Abbreviation：YYZ
City Population：2790060
City Surface Area：630.2

                         Do you want to continue?
                         [type 1 (for yes) - type 0 (for no)]: 1
MENU OPTIONS :
        < 1 . ADD Cities >
        < 2 . PRINT Cities >
        < 3. SEARCH FOR A City BY Code Area >
        < 4. SEARCH BY NAME>
        < 5. Find The City Having The Highest Surface Area>
        < 6. Order The Cities Array By Surface Area>
 ENTER YOUR CHOICE: 4

 SEARCH FOR A City BY NAME:
 ENTER NAME: Toronto

City Name：Toronto
City Code Area：416
City Abbreviation：YYZ
City Population：2790060
City Surface Area：630.2

                         Do you want to continue?
                         [type 1 (for yes) - type 0 (for no)]: 1
MENU OPTIONS :
        < 1 . ADD Cities >
        < 2 . PRINT Cities >
        < 3. SEARCH FOR A City BY Code Area >
        < 4. SEARCH BY NAME>
        < 5. Find The City Having The Highest Surface Area>
        < 6. Order The Cities Array By Surface Area>
 ENTER YOUR CHOICE: 5

 FIND THE CITY HAVING THE HIGHEST SURFACE AREA
City Name：Toronto
City Code Area：416
City Abbreviation：YYZ
City Population：2790060
City Surface Area：630.2

                         Do you want to continue?
                         [type 1 (for yes) - type 0 (for no)]: 1
MENU OPTIONS :
        < 1 . ADD Cities >
        < 2 . PRINT Cities >
        < 3. SEARCH FOR A City BY Code Area >
        < 4. SEARCH BY NAME>
        < 5. Find The City Having The Highest Surface Area>
        < 6. Order The Cities Array By Surface Area>
 ENTER YOUR CHOICE: 6

 Order The Cities Array By Surface Area

 Order Cities by Surface Area(using reference)
List of Cities
City Name：Vancouver
City Code Area：604
City Abbreviation：YVR
City Population：2463431
City Surface Area：114.97
--------------------------------------------
City Name：Montreal
City Code Area：514
City Abbreviation：YUL
City Population：1780000
City Surface Area：431.5
--------------------------------------------
City Name：Toronto
City Code Area：416
City Abbreviation：YYZ
City Population：2790060
City Surface Area：630.2
--------------------------------------------

                         Do you want to continue?
                         [type 1 (for yes) - type 0 (for no)]: 0

 This application written by Jiarui Li-2014570
*/