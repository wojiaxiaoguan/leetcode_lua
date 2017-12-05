local function twoSum_Force( array,target )
    local len = #array;
    for i=1,len do
        for j=i+1,len do
            if array[i] + array[j] == target then
                return {i,j}
            end
        end
    end
    return  nil;
end

local function twoSum_Map( array,target )
    local len = #array;
    local map = {}
    for i,v in ipairs(array) do
        map[v] = i;
    end
    for i=1,len do
        local temp = target - array[i];
        if map[temp] and map[temp] ~= i then
            return {i,map[temp]};
        end
    end
    return  nil;
end

local function twoSum_MapImprove( array,target )
    local len = #array;
    local map = {}
    for i=1,len do
        local temp = target - array[i];
        if map[temp] then
            return {i,map[temp]};
        end
        map[array[i]] = i;
    end
    return  nil;
end



local function main(  )
    local arr = {2,7,11,15,2,5,6,9,10,0,20};
    local target = 15;
    local ret = twoSum_Force(arr,target);
    print("ret={",ret[1],",",ret[2],"}");

    local ret1 = twoSum_Map(arr,target);
    print("ret1={",ret[1],",",ret[2],"}");

     local ret2 = twoSum_MapImprove(arr,target);
    print("ret2={",ret[1],",",ret[2],"}");
end

main();

