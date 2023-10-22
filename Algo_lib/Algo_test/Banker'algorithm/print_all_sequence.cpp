// Print all the safe-sequences
void safe_sequence(bool marked[], int allocated[][R], int max[][R],
                   int need[][R], int available[], vector<int> safe)
{
 
    for (int i = 0; i < P; i++) {
 
        // check if it is not marked
        // already and can be allocated
        if (!marked[i] && is_available(i, allocated, max, need, available)) {
 
            // mark the process
            marked[i] = true;
 
            // increase the available
            // by deallocating from process i
            for (int j = 0; j < R; j++)
                available[j] += allocated[i][j];
 
            safe.push_back(i);
            // find safe sequence by taking process i
            safe_sequence(marked, allocated, max, need, available, safe);
            safe.pop_back();
 
            // unmark the process
            marked[i] = false;
 
            // decrease the available
            for (int j = 0; j < R; j++)
                available[j] -= allocated[i][j];
        }
    }
 
    // if a safe-sequence is found, display it
    if (safe.size() == P) {
 
        total++;
        for (int i = 0; i < P; i++) {
 
            cout << "P" << safe[i] + 1;
            if (i != (P - 1))
                cout << "--> ";
        }
 
        cout << endl;
    }
}