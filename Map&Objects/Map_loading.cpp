#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct ArrayWrapper{
    vector<vector<char>> TDVEC;
};


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
            ArrayWrapper MapToArray(ifstream&);
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
   ArrayWrapper Converter = MapToArray(inputline);
    cout<<Converter.TDVEC[0][1]<<endl;

}

ArrayWrapper Maps::MapToArray(ifstream& inputline)
{
    ArrayWrapper Converter;
    char ch;
    int height_tracker = 0;
    int width_tracker = 0;
    Converter.TDVEC.resize(map_height);
    while (inputline >> noskipws >> ch)
    {
        if (ch != '\n')
        {
            Converter.TDVEC[height_tracker].push_back(ch);
                if (width_tracker==map_width-1)
                {
                    height_tracker++;
                    if (height_tracker==map_height)
                    {
                        inputline.close();
                        break;
                    }
                    width_tracker = -1;
                }

            width_tracker++;
        }
    }

    return Converter;
}


