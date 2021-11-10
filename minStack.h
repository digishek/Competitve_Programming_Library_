//
// Created by digishek on 10/11/21.
//
#include<bits/stdc++.h>

#ifndef COMPETITVE_PROGRAMMING_LIBRARY__MINSTACK_H
#define COMPETITVE_PROGRAMMING_LIBRARY__MINSTACK_H

template<class T>
class minStack {
    std::stack<std::pair<T,T>> st;
public:
    void push(const T& value){
        T mn = value ;
        if(!st.empty()) mn =min(mn , st.top().second) ;
        st.push({value ,mn}) ;
    }
    T findMin(){
        return st.top().second ;
    }
    void pop(){
        st.pop() ;
    }
};


#endif //COMPETITVE_PROGRAMMING_LIBRARY__MINSTACK_H
