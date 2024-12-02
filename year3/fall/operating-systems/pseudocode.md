# PSEUDO CODE FOR OS ALGORITHMS
## SCHEDULING
firstcomefirstserve(processes[]):
    int currenttime = 0;
    for process in processes:
        if currenttime < process.arrivaltime:
            currenttime = process.arrivaltime;
        process.completiontime = currenttime + process.bursttime;
        currenttime = process.completiontime;
        process.turnaroundtime = process.completiontime - process.arrivaltime;
        process.waitingtime = process.turnaroundtime - process.bursttime;
        
shortestjobfirst(processes[]):
    int currenttime = 0;
    int completed = 0;
    while incomplete processes: #(complete<len(processes))
        int index = -1;
        int minburst = 1e9; #initialize to very high value
        for process in processes:
            if not process.iscomplete and process.arrivaltime <= currenttime:
                if process.bursttime lt minburst:
                    minburst = process.bursttime;
                    index = index(process);
        if index == -1:
            currenttime++;
            continue
        processes[index].completiontime = currenttime + processes[index].bursttime;
        processes[index].turnaroundtime = processes[index].completiontime - processes[index].arrivaltime;
        processes[index].waitingtime = processes[index].turnaroundtime - processes[index].bursttime;
        currenttime = processes[index].completiontime;
        processes[index].iscomplete = true;
        completed++;
        
roundrobin(processes[], quantum):
    int currenttime = 0;
    int completed = 0;
    while completed < len(processes):
        for process in processes:
            if process.remainingtime > 0 and process.arrivaltime <= currenttime:
                if process.remainingtime > quantum:
                    currenttime += quantum;
                    process.remainingtime -= quantum;
                else:
                    currenttime += process.remainingtime;
                    process.remainingtime = 0;
                    process.completiontime = currentime;
                    process.turnaroundtime = process.completiontime - process.arrivaltime;
                    process.waitingtime = process.turnaroundtime - process.bursttime;
                    completed++
                    
## MEMORY
firstinfirstout(pages[], numberframes):
    int frames[numberframes];
    int front = 0;
    int pagefaults = 0;
    for frame in frames:
        frame = -1;
    for page in pages:
        int found = 0;
        for frame in frames:
            if frame == page:
                found = 1;
                break;
        if not found:
            frames[front] = page;
            front = (front + 1) % numberframes;
            pagefaults++;
    print(pagefaults);
    
leastrecentlyused(pages[], numberframes):
    int frames[numberframes];
    int times[numberframes];
    int pagefaults = 0;
    int count = 0;
    for frame in frmaes:
        frame = -1;
    for page in pages:
        int found = 0;
        for frame in frames:
            if frame == page:
                found = 1;
                time[index(frame)] = count++;
                break;
        if not found:
            int min = times[0];
            int pos = 0;
            for time in times:
                if time < min:
                    min = time;
                    pos = index(time);
            frames[pos] = page;
            times[pos] = count++;
            pagefaults++;
    print(pagefaults);
    
secondchance(pages[], numberframes):
    int frames[numberframes];
    int ref[frames];
    int front = 0;
    int pagefaults = 0;
    for i in len(frames):
        frames[i] = -1;
        ref[i] = 0;
    for page in pages:
        int found = 0;
        for i in len(frames):
            if frames[i] == page:
                found = 1;
                ref[i] = 1;
                break;
        if not found:
            while ref[front] == 1:
                ref[front] = 0;
                front = (front + 1) % numberframes;
            frame[front] = page;
            ref[front] = 1;
            front = (front + 1) % frames;
            pagefaults++;
    print(pagefaults);
                
