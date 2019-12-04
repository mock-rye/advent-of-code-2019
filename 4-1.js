function checker(number){
    let str = String(number)
    let adjacent = false
    for(let it = 0; it < 6; ++it){
        if(str[it] > str[it+1]) return false
        if(str[it] == str[it+1]) adjacent = true
    }
    return adjacent
}

let lower = prompt('input lower bound', 0)
let upper = prompt('input upper bound', 999999)
let counter = 0
for(let iterator = lower; iterator <= upper; ++iterator){
    if(checker(iterator)) ++counter
}
console.log(counter)