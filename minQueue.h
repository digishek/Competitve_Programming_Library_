//
// Created by digishek on 10/11/21.
//
#include<bits/stdc++.h>

#ifndef COMPETITVE_PROGRAMMING_LIBRARY__MINQUEUE_H
#define COMPETITVE_PROGRAMMING_LIBRARY__MINQUEUE_H

template<class T>
class minQueue {
    std::stack<pair<T,T>> s1,s2 ;
    void push(T value ){
        T mn = value ;
        if(!s1.empty()) mn= min(mn , s1.top()) ;
        s1.push({value ,mn}) ;
    }

    void pop(){
        if(s2.empty()){
          while(!s1.empty()){
              T value = s1.top().first , mn = s1.top().second ;
              s1.pop();
              if(!s2.empty()) mn= min(mn , s2.top()) ;
              s2.push({value ,mn}) ;
          }
        }
        s1.pop() ;
    }
    T getMin(T value ){
        if(s1.empty() || s2.empty()){
            if(s1.empty()) return s2.top().second ;
            else return s1.top().second ;
        }
    }
};


#endif //COMPETITVE_PROGRAMMING_LIBRARY__MINQUEUE_H
