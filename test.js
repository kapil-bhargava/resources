// let arr = [3, 1, 9, 4];

// let decArr = [];    // will store numbers in decreasing order
// let g = arr[0];     // assume the first element is the greatest

// for (let i = 0; i < arr.length; i++) {
//   if (arr[i] > g) {
//     // If we find a number greater than current greatest (g)
//     g = arr[i];      

//     // Put this new greatest at the beginning of decArr
//     decArr.unshift(g);
//   }
// }

// console.log(decArr);


// =============================
// RANK STUDENTS WITHOUT USING sort()
// =============================

// Dataset of students
const students = [
  {
    name: "Amit Kumar",
    gender: "Male",
    age: 15,
    class: "10th",
    marks: { math: 78, eng: 55, science: 62 }
  },
  {
    name: "Riya Sharma",
    gender: "Female",
    age: 14,
    class: "9th",
    marks: { math: 35, eng: 42, science: 38 }
  },
  {
    name: "Arjun Verma",
    gender: "Male",
    age: 16,
    class: "11th",
    marks: { math: 90, eng: 88, science: 95 }
  },
  {
    name: "Priya Singh",
    gender: "Female",
    age: 15,
    class: "10th",
    marks: { math: 28, eng: 30, science: 25 }
  },
  {
    name: "Karan Gupta",
    gender: "Male",
    age: 14,
    class: "9th",
    marks: { math: 50, eng: 48, science: 39 }
  }
];

// =============================
// STEP 1: Calculate total marks for each student
// =============================
for (let student of students) {
  let total = 0;

  // Loop through all subjects of current student
  for (let subject in student.marks) {
    total += student.marks[subject]; // Add subject marks
  }

  // Add a new property "total" to store total marks
  student.total = total;
}

// =============================
// STEP 2: Assign rank WITHOUT using sort()
// =============================
// Logic: For each student, start with rank = 1.
// Then compare with every other student.
// If another student has higher total marks, increase rank.
// Finally assign that rank to the student.

for (let i = 0; i < students.length; i++) {
  let rank = 1; // every student starts at rank 1

  // Compare student[i] with all other students
  for (let j = 0; j < students.length; j++) {
    if (students[j].total > students[i].total) {
      rank++; // increase rank if someone has more marks
    }
  }

  // Assign the calculated rank to student[i]
  students[i].rank = rank;
}

// =============================
// OUTPUT RESULT
// =============================
console.log("Final Ranking:");
for (let s of students) {
  console.log(`${s.rank}. ${s.name} → Total: ${s.total}`);
}