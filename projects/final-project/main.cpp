#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Mountain {
    string name;
    string country;
    double elevation;
    
public:
// constructor/setter
Mountain(string name, string country, double elevation){
    this->name = name;
    this->country = country;
    this->elevation = elevation;
}
  //getters  
    string getName() const{
        return name;
    }
    string getCountry() const{
        return country;
    }
    double getElevation() const{
        return elevation;
    }
    double toMeters(double elevation){
        return elevation / 3.2808;
    }
};

double minElevation(vector<Mountain> mts){
    double min = mts.at(0).getElevation();
    int index = 0;
    for(int i = 0; i < mts.size() - 1;i++){
       if(min > mts.at(i).getElevation()){
           index = i;
           min = mts.at(i).getElevation();
       }
    }
       return mts[index].getElevation();
    }

int main() {
 
    vector<Mountain> mts = {
        Mountain("Chimborazo", "Ecuador", 20549),
        Mountain("Matterhorn", "Switzerland", 14692),
        Mountain("Olympus", "Greece", 9573),
        Mountain("Everest", "Nepal", 29029),
        Mountain("Mount Marcy - Adirondacks", "United States", 5344),
        Mountain("Mount Mitchell - Blue Ridge", "United States", 6684),
        Mountain("Zugspitze", "Switzerland", 9719)
    };

    for (unsigned int j = 0; j < mts.size()-1; j++)
    {

        cout << "Mountain: " << mts.at(j).getName() << endl;
        cout << "Country: " << mts.at(j).getCountry() << endl;
        cout << "Elevation: " << mts.at(j).getElevation() << " ft (" << mts.at(j).toMeters(mts.at(j).getElevation()) << "m)" << endl << endl;
    }
    
    double match = minElevation(mts);
    for (int z = 0; z < mts.size()-1; z++){
        if (match == mts.at(z).getElevation()){
            cout << mts.at(z).getName() << " located in " << mts.at(z).getCountry()
            << " has the lowest elevation of " << mts.at(z).getElevation()  << "ft (" << mts.at(z).toMeters(mts.at(z).getElevation()) << "m)" << endl;
            break;
        }
    }
    return 0;
}