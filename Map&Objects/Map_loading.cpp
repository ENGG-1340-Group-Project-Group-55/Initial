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
            void MapToArray(ifstream&);
            void Location_accessor();
        };

int main(){
    Maps Mp(15,30);
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
    inputline.open("/Users/lucas/Documents/GitHub/Initial/Map&Objects/Map_resources/15-15_map.txt");
    if (inputline.fail()){
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    MapToArray(inputline);

}

void Maps::MapToArray(ifstream& inputline) {
    char ch;
    int height_tracker = 0;
    int width_tracker = 0;
    char td_map [map_height][map_width];
                while (inputline >> noskipws >> ch) {
                    cout<<"height_tracker: "<<height_tracker<<endl;
                    cout<<"width_tracker: "<<width_tracker<<endl<<endl;
                    td_map[height_tracker][width_tracker] = ch;
                    if (width_tracker==map_width-1){
                        width_tracker=-1;
                        height_tracker++;
                        if (height_tracker==map_height){
                            break;
                        }
                    }
                    width_tracker++;
                }

                for (int i=0;i<map_height;i++){
                    for (int j=0;j<map_width;j++){
                        cout<<td_map[i][j];
                    }
                }

    inputline.close();
        }
