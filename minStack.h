//
// Created by digishek on 10/11/21.
//
#include<bits/stdc++.h>

#ifndef COMPETITVE_PROGRAMMING_LIBRARY__MINSTACK_H
#define COMPETITVE_PROGRAMMING_LIBRARY__MINSTACK_H

class<T>
class minStack {
    stack<pair<T,T>> st;
    void push(const T& value){
        T mn = value ;
        if(!st.empty()) mn =min(mn , T.top().second) ;
        st.push({T ,mn}) ;
    }
    T findMin(){
        return st.top().second ;
    }
    void pop(){
        st.pop() ;
    }
};


#endif //COMPETITVE_PROGRAMMING_LIBRARY__MINSTACK_H
