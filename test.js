let arr = [3,1,9,4];

let decArr = [];    // for storing the elements in decreasing order
for(let i=0; i<arr.length; i++){
    let count = 0;
    for(let j=0; j<arr.length; j++){
        if(arr[i] < arr[j]){
            count++;
        }
    }
    decArr[count] = arr[i];
}
console.log(decArr);