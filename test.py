from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
import time


chrome_options = Options()
SCROLL_PAUSE_TIME = 1


chrome_options.add_argument("--start-maximized")
chrome_options.add_argument("--disable-notifications")


driver = webdriver.Chrome('./chromedriver', chrome_options = chrome_options)

driver.get("https://www.reddit.com/r/hardwareswap/new")

#driver.find_element_by_xpath("//*[@id='header-search-bar']").send_keys("Asus")

#driver.find_element_by_xpath("//*[@id='header-search-bar']").send_keys(Keys.ENTER)
# Get scroll height
last_height = driver.execute_script("return document.body.scrollHeight")

post = open('./posts.txt', 'w')

posts = driver.find_elements_by_class_name("_eYtD2XCVieq6emjKBH3m")

for i in range(0,5):
    # Scroll down to bottom
    for things in posts:
        post.write(things.text)
        post.write("\n")

    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")

    # Wait to load page
    time.sleep(SCROLL_PAUSE_TIME)

    # Calculate new scroll height and compare with last scroll height
    new_height = driver.execute_script("return document.body.scrollHeight")
    if new_height == last_height:
        break
    last_height = new_height


post.close()