/*
PmergeMe(sequence):

    IF sequence.size <= 1
        return sequence


    // STEP 1: Create pairs

    pairs = []
    straggler = NONE

    FOR i = 0 TO size - 2 STEP 2

        a = sequence[i]
        b = sequence[i + 1]

        IF a > b
            swap(a, b)
        END IF

        pairs.push([a, b])

    END FOR


    // STEP 2: Handle odd element

    IF sequence.size is odd
        straggler = last element
    END IF


    // STEP 3: Extract big elements

    bigElements = []

    FOR each pair

        bigElements.push(pair.big)

    END FOR


    // STEP 4: Recursively sort big elements

    sortedBig = PmergeMe(bigElements)


    // STEP 5: Rebuild the relationships

    // Every big element must still know its
    // corresponding small element.

    MAIN = sortedBig

    PEND = corresponding small elements


    // STEP 6: Insert first pending element

    insert PEND[first] into MAIN


    // STEP 7: Generate Jacobsthal insertion order

    order = generateJacobsthalOrder(PEND.size)


    // STEP 8: Insert remaining pending elements

    FOR each index in order

        value = PEND[index]

        partner = corresponding BIG element

        limit = position(partner, MAIN)

        binary search value
        only inside MAIN[0 ... limit)

        insert value

    END FOR


    // STEP 9: Insert straggler

    IF straggler exists

        binary search its position in MAIN

        insert straggler

    END IF


    RETURN MAIN
*/