#Bugs and Fixes
 
#1. Of by One: Changed i < end to i <= end so that it can include the last value

#2.1 Changed sign from <= to < due to out of bounds error. It is checking another item in the vector after the final with the <= due t0  .size

#2.2 changed sign from > 0 to < 0 so it checks for numbers less than 0 not more than 0 

#3.1 Changed return 0 ---> "throw std::invaild_argument("...")" 
#3.2 Chnaged i <= numbers.size() to i < numbers.size()
#3.3 changed numbers[i] >= to > for duplicate values in vector