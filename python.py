# Import the required libraries
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
import time

# Function to parse duration in HH:MM:SS format to seconds
def parse_duration(duration):
    parts = duration.split(':')
    if len(parts) == 2:
        minutes, seconds = map(int, parts)
        hours = 0
    elif len(parts) == 3:
        hours, minutes, seconds = map(int, parts)
    else:
        return 0
    return hours * 3600 + minutes * 60 + seconds

# Set up the Selenium WebDriver
chrome_options = webdriver.ChromeOptions()
chrome_options.add_experimental_option('detach',True)
driver = webdriver.Chrome(options=chrome_options)

# Step 3: Navigate to the YouTube playlist page
playlist_url = 'https://www.youtube.com/playlist?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA'  # Replace with your playlist URL
driver.get(playlist_url)

time.sleep(5)  # Wait for the page to load

# Step 4: Extract video details
video_elements = driver.find_elements(By.CSS_SELECTOR, 'ytd-playlist-video-renderer')

# Initialize counters
total_duration = 0
number_of_videos = 0

# Skip the first 20 videos and start calculating from the 21st video
for video in video_elements[20:]:
    duration_element = video.find_element(By.CSS_SELECTOR, 'span.ytd-thumbnail-overlay-time-status-renderer')
    duration_text = duration_element.text.strip()
    total_duration += parse_duration(duration_text)
    number_of_videos += 1

# Step 5: Calculate and print the total length and number of videos
total_hours = total_duration // 3600
total_minutes = (total_duration % 3600) // 60
total_seconds = total_duration % 60

print(f'Total number of videos after the 20th: {number_of_videos}')
print(f'Total length of playlist after the 20th video: {total_hours} hours, {total_minutes} minutes, {total_seconds} seconds')

# Close the WebDriver
driver.quit()
