# Majority Element

* Have a count variable initialized to 0 and a majority variable

    `int count =0;`

    `int maj= nums[0];`

  
* iterate over for Loop
  - If `maj` == nums --> then increment count
  - else --> decrement  ***`count`*** 
            <br/>&nbsp;&nbsp;&nbsp;&nbsp;Also if `count` == -1  then --> `maj` = currentElement & `count` = 1
* return ***maj***