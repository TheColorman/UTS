if __name__ == '__main__':
    days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    # Can't name 'sum' here because 'sum' is a key word
    sum1 = 0

    for index in range(0, len(days)):
        sum1 += days[index]

    average = sum1 / len(days)  
    
    print('Average days per month = %.15f' %average)
