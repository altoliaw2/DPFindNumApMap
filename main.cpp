#include <iostream>

void fn_GetNum(int** i2p_Map, int& i_M, int& i_N);

int main(){
    int i_M = -1;
    int i_N = -1;
    std::cin>> i_M >> i_N;
    int** i2p_Map = new int*[i_M +1];
    for(int i_Ct=0; i_Ct< (i_M +1); i_Ct++){
        i2p_Map[i_Ct] = new int[i_N + 1]{};
    }

    fn_GetNum(i2p_Map, i_M, i_N);


    for(int i_Ct=0; i_Ct< (i_M +1); i_Ct++){
        delete [] i2p_Map[i_Ct];
    }
    delete i2p_Map;
    return 0;
}

void fn_GetNum(int** i2p_Map, int& i_M, int& i_N){
    for(int i_Ct=0; i_Ct< i_M+1; i_Ct++){
        i2p_Map[i_Ct][0] = 1;
    }

    for(int i_Ct=0; i_Ct< i_N+1; i_Ct++){
        i2p_Map[0][i_Ct] = 1;
    }

    for(int i_Ct=1; i_Ct< i_M+1; i_Ct++){
        for(int i_Ct2=1; i_Ct2< i_N+1; i_Ct2++){
            i2p_Map[i_Ct][i_Ct2] = i2p_Map[i_Ct-1][i_Ct2] +
                                    i2p_Map[i_Ct][i_Ct2-1];
        }
    }

    std::cout<< i2p_Map[i_M][i_N];
}
