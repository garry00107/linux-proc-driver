import os

def read_from_driver():
    try:
        with open("/proc/Pyjama_driver", "r") as driver_handle:
            message = driver_handle.readline()
            print("[Kernel Message]:", message.strip())
    except Exception as e:
        print("Error reading from driver:", e)

def write_to_driver(data):
    try:
        with open("/proc/Pyjama_driver", "w") as driver_handle:
            driver_handle.write(data)
            print("[User] Successfully wrote to driver:", data)
    except Exception as e:
        print("Error writing to driver:", e)

def main():
    while True:
        print("\nOptions:")
        print("1. Read from driver")
        print("2. Write to driver")
        print("3. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            read_from_driver()
        elif choice == "2":
            data = input("Enter data to write: ")
            write_to_driver(data)
        elif choice == "3":
            print("Exiting...")
            break
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()
