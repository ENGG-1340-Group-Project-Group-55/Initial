#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Maps
        {
    private:
            int Map_height;
            int Map_width;
    public:
            Maps(int,int);
            int map_height;
            int map_width;
            void Map_Loader();
            void MapToArray(ifstream&,string);
            void Location_accessor();
        };

int main(){
    Maps Mp(15,15);
    Mp.Map_Loader();
}

Maps::Maps(int a,int b){
    Map_height = a;
    Map_width = b;
    map_height = Map_height;
    map_width = Map_width;
}

void Maps::Map_Loader() {
    ifstream inputline;
    string nextline;
    inputline.open("/Users/lucas/Documents/GitHub/Initial/ghost1.txt");
    if (inputline.fail()){
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    MapToArray(inputline,nextline);

}

void Maps::MapToArray(ifstream& inputline, string nextline) {
    //char td_map [map_height][map_width];
        //for (int i=0;i<map_height;i++){
            //for (int j=0;j<map_width;j++){


            //}
        //}

    while (getline(inputline,nextline)){
        cout<<nextline<<endl;
    }
    inputline.close();


}
