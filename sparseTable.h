//
// Created by digishek on 10/11/21.
//
#inlude<vector>

#ifndef COMPETITVE_PROGRAMMING_LIBRARY__SPARSETABLE_H
#define COMPETITVE_PROGRAMMING_LIBRARY__SPARSETABLE_H

#include<vector>
#include<iostream>
#include <cmath>

template<class T , T (*func)(T,T)>
class sparseTable {
    const int N ,K  ;
    std::vector<std::vector<T>> pre ;
    std::vector<T> arr ;

public:
    sparseTable(const std::vector<T> &Arr , int MAXN   ): N(MAXN) , arr(Arr) , K(log2(K) +1)  {
        pre.resize(N , vector<T>(K)) ;
        for(int i= 0 ;i< N ;i++){
            pre[i][0] = func(arr[i]) ;
        }
        for(int j=1 ; j<K ;j++){
            for(int i=0 ;i<N ;i++){
                pre[i][j] = func(pre[i][j-1] ,pre[i+ 1<<(j-1)][j-1]) ;
            }
        }
    }
    sparseTable(){
        std::cerr<<"please add vector and maximum value "  ;
        throw  ;
    }

    T query(int l ,int r){
        T res = T{} ;
        for(int j=K ; j>=0 ;j--){
            if(1+ r-l >= 1<<j){
                res= func(res ,pre[l][j] )  ;
                l+= 1<<j ;
            }
        }
        return res ;
    }

};




#endif //COMPETITVE_PROGRAMMING_LIBRARY__SPARSETABLE_H
