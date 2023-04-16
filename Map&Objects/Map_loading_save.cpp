#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct VectorWrapper{
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
    VectorWrapper Map_Loader();
    VectorWrapper MapToArray(ifstream&);
    void Map_printer(VectorWrapper);
};


int main(){
    Maps Mp(15,30);
    VectorWrapper Converter = Mp.Map_Loader();
    Mp.Map_printer(Converter);
}

Maps::Maps(int a,int b){
    Map_height = a;
    Map_width = b;
    map_height = Map_height;
    map_width = Map_width;
}


VectorWrapper Maps::Map_Loader() {
    ifstream inputline;
    string nextline;
    inputline.open("/Users/M1/Documents/GitHub/Initial/Map&Objects/Map_resources/15-15_map.txt");
    if (inputline.fail()){
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    VectorWrapper Converter = MapToArray(inputline);
    return Converter;

}

VectorWrapper Maps::MapToArray(ifstream& inputline)
{
    VectorWrapper Converter;
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

void Maps::Map_printer(VectorWrapper Converter)
{

    for (int i=0;i<map_height;i++){
        for(int j=0;j<map_width;j++){
            if (j==map_width-1){
                cout<<Converter.TDVEC[i][j]<<endl;
            }
            else{
                cout<<Converter.TDVEC[i][j];
            }

        }
    }

}