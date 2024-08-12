# Angela’s Calendar

On Angela's calendar, one year is composed of 15 months, and each month always consists of 30 days. On that calendar, there are 5 days in a week, which are Monday, Tuesday, Wednesday, Thursday and Friday. 

If today is Monday, then tomorrow will be Tuesday, the day after tomorrow will be Wednesday. After 5 days it will be Monday. 

Today is the d1-th day in the m1-th month of year y1. Given the day of today on Angela's calendar, what day will it be (or was it) on the d2-th day in the m2-th month of year y2 on Angela's calendar? 

**Input**  

For each test case: The first line contains three integers d1, m1, y1 and a string s, indicating the date and day of today on Angela's calendar. 

$$
(1 <= d_1 <= 30,1 <= m_1 <= 15,2000 <= y_1 <= 10^{9})
$$

The second line contains three integers d2, m2, y2, indicating the date whose day we want to know. 

$$
(1 <= d_2 <= 30,1 <= m_2 <= 15,2000 <= y_2 <= 10^{9})
$$

**Output**

For each test case output one line containing one string, indicating the day of the d2-th day in the m2-th month of year y2 on Angela's calendar.

**Sample Input**
15 8 2020 Monday

16 8 2020

15 8 2020 Tuesday

14 12 2020

15 8 2020 Friday

1 1 1000000000

1 1 1000000000 Wednesday

15 8 2020

**Sample Output**

Tuesday

Monday

Monday

Tuesday


**HINT**: To transfer a string to an integer, you can use Integer.parseInt(). Pay attention to case sensitivity.
