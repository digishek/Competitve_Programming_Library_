//
// Created by digishek on 10/11/21.
//


#ifndef COMPETITVE_PROGRAMMING_LIBRARY__SPARSETABLE_H
#define COMPETITVE_PROGRAMMING_LIBRARY__SPARSETABLE_H

#include<vector>
#include<iostream>
#include <cmath>

// func represents a function pointer to a functions which performs operation on two value
// e represents a values such that func(value ,e) = value for each value in the valid range
// for example use  sparseTable(int , min<int,int> , INT_MAX)
// for query in range l and r (inclusive) just use query(l,r)

template<class T , T (*func)(const T&,const T&), T e>
class sparseTable {
    const int N ,K  ;
    std::vector<std::vector<T>> pre ;
    std::vector<T> arr ;

public:
    sparseTable(const std::vector<T> &Arr , int MAXN   ): N(MAXN) , arr(Arr) , K(log2(N) +1)  {
        pre.resize(N , vector<T>(K)) ;
        for(int i= 0 ;i< N ;i++){
            pre[i][0] = func(arr[i],e) ;
        }
        for(int j=1 ; j<K ;j++){
            for(int i=0 ;i + (1 << j) <= N ;i++){
                pre[i][j] = func(pre[i][j-1] ,pre[i+ (1<<(j-1))][j-1]) ;

            }
        }
    }


    T query(int l ,int r){
        T res = e ;
        for(int j=K ; j>=0 && l<=r ;j--){
            if(1+ r-l >= 1<<j){
                res= func(res ,pre[l][j] )  ;
                l+= 1<<j ;
            }

        }
        assert(l>r) ;
        return res ;
    }

}



#endif //COMPETITVE_PROGRAMMING_LIBRARY__SPARSETABLE_H
