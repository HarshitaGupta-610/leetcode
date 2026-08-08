# Write your MySQL query statement below
select Prices.product_id,
round(
    case 
    when sum(UnitsSold.units) is null then 0
    else sum(UnitsSold.units*Prices.price) / sum(UnitsSold.units) 
    end ,2) 
as average_price
from Prices
left join UnitsSold
on Prices.product_id = UnitsSold.product_id
And UnitsSold.purchase_date between Prices.start_date and Prices.end_date
group by Prices.product_id;


