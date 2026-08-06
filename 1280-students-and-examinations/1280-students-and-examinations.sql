# Write your MySQL query statement below
-- Question kya bol raha hai?
-- Hume har student ke liye har subject ka exam attendance count nikalna hai.
-- Agar kisi student ne kisi subject ka exam kabhi nahi diya,
-- tab bhi uska count 0 ke saath output me aana chahiye.
SELECT
    Students.student_id,
    Students.student_name,
    Subjects.subject_name,
    -- Examinations.student_id sirf tab count hoga jab exam record exist kare.
    -- Agar LEFT JOIN ke baad NULL hua to COUNT usse ignore karega.
    -- Isliye Bob-Physics ya Alex-Math ka count automatically 0 aa jayega.
    COUNT(Examinations.student_id) AS attended_exams
-- Sabse pehle Students table lo.
FROM Students
-- CROSS JOIN ka matlab:
-- Har student ko har subject ke saath pair bana do.
CROSS JOIN Subjects
-- Ab in sab combinations me exam records attach karo.
LEFT JOIN Examinations
-- Same student aur same subject ke records hi match honge.
ON Students.student_id = Examinations.student_id
AND Subjects.subject_name = Examinations.subject_name
-- Ab ek student ke ek subject ki saari matching rows ko ek group bana do.
-- Example:
-- Alice Math
-- Alice Physics
-- Bob Math
-- Bob Physics
GROUP BY
    Students.student_id,
    Students.student_name,
    Subjects.subject_name
-- Question ne bola hai output student_id aur subject_name ke according sort karo.
ORDER BY
    Students.student_id,
    Subjects.subject_name;-- Question kya bol raha hai?
