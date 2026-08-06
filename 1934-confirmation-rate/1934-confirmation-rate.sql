# Write your MySQL query statement below
-- Hume har user ka confirmation rate nikalna hai.
-- Confirmation Rate = confirmed messages / total confirmation requests.

SELECT
    -- Har user ki ID dikhani hai.
    Signups.user_id,

    -- Final answer ko 2 decimal places tak round karna hai.
    ROUND(

        -- AVG isliye use kar rahe hain kyunki:
        -- confirmed = 1
        -- timeout = 0
        --
        -- Example:
        -- User 7 -> 1,1,1
        -- AVG = (1+1+1)/3 = 1.00
        --
        -- User 2 -> 1,0
        -- AVG = (1+0)/2 = 0.50
        --
        -- User 3 -> 0,0
        -- AVG = 0

        AVG(

            -- Agar action confirmed hai to 1 return karo,
            -- warna (timeout ya NULL) 0 return karo.
            CASE
                WHEN Confirmations.action = 'confirmed'
                THEN 1
                ELSE 0
            END

        ),

        -- 2 decimal places
        2

    ) AS confirmation_rate

-- Saare users Signups table me hain,
-- isliye Signups se start karenge.
FROM Signups

-- LEFT JOIN use karenge kyunki
-- hume har user chahiye, chahe usne confirmation request bheji ho ya nahi.
LEFT JOIN Confirmations

-- Same user ke confirmation records ko join karo.
ON Signups.user_id = Confirmations.user_id

-- Har user ka alag group banao.
GROUP BY Signups.user_id;