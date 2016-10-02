Design a program that analyzes the performance of the stocks
managed by a local stock trading company and at the end of each day
produce a listing of those stocks ordered by the stock symbol. The company’s
investors also would like see another listing of the stocks, which is
ordered by the percent gained by eack stock.
Because the company also requires you to produce the list ordered by the
percent gain/loss, you need to sort the stock list by this component. However,
you are not to physically sort the list by the component percent gain/loss;
instead, you will provide a logical ordering with respect to this component.
To do so, add a data member, a vector, to hold the indices of the stock list
ordered by the component percent gain/loss. Call this vector indexByGain.
When printing the list ordered by the component percent gain/loss, use the
array indexByGain to print the list. The elements of the array indexByGain
will tell which component of the stock list to print next.
