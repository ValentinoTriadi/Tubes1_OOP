#ifndef ROUND_ROBIN_HPP_
#define ROUND_ROBIN_HPP_

#include <queue>
#include <iostream>

template <class T>
class roundRobin{
    private:
        std::queue<T> buf;
    public:
        /**
         * @brief Construct a new round Robin object
        */
        roundRobin(){
            buf = std::queue<T>();
        }
        /**
         * @brief Add a new element to the queue
         * 
         * @param elem 
         */
        ~roundRobin(){}


        /**
         * @brief Get the first element
         * 
         * @return T 
         */
        T top(){
            return buf.front();
        }

        /**
         * @brief Move first element into last
         * @return first element
        */
        T next(){
            T temp = buf.front();
            buf.pop();
            buf.push(temp);
            return temp;
        }

        /**
         * @brief Add a new element into last element
         * 
         * @param elem 
        */
        void add(T elem){
            buf.push(elem);
        }

        /**
         * @brief Delete first element
        */
        void deleteFirst(){
            buf.pop();
        }

        /**
         * @brief Find index of element
         * 
         * @param elem
         * 
         * @return index of element if found, -1 if not found
        */
        int findIdx(T elem){
            std::queue<T> temp = buf;
            int idx = 0;
            while(!temp.empty()){
                if(temp.front() == elem){
                    return idx;
                }
                temp.pop();
                idx++;
            }
            return -1;
        }

        /**
         * @brief Get the size of queue
         * 
         * @return int 
        */
        int size(){
            return buf.size();
        }

        /**
         * @brief Check if queue is empty
         * 
         * @return true if empty, false if not
        */
        bool isEmpty(){
            return buf.empty();
        }

        /**
         * @brief Clear the queue
        */
        void clear(){
            while(!buf.empty()){
                buf.pop();
            }
        }

        /**
         * @brief Print the queue
        */
        friend std::ostream& operator << (std::ostream& os, roundRobin<T>& r){
        int size = r.buf.size();
        os << "(";
        for (int i = 0; i < size; i++){
            os << r.buf.front();
            if (i != size - 1) os << ", ";
            r.next();
        }
        os << ")" << std::endl;
        return os;
    }

};

#endif // ROUND_ROBIN_HPP_