from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
import time


chrome_options = Options()
SCROLL_PAUSE_TIME = 1


chrome_options.add_argument("--start-maximized")
chrome_options.add_argument("--disable-notifications")


driver = webdriver.Chrome('./chromedriver', chrome_options = chrome_options)

driver.get("https://cnj.craigslist.org/d/computers/search/sya")

#driver.find_element_by_xpath("//*[@id='header-search-bar']").send_keys("Asus")

#driver.find_element_by_xpath("//*[@id='header-search-bar']").send_keys(Keys.ENTER)
# Get scroll height

c_posts = driver.find_elements_by_class_name("result-title")

for post in c_posts:
    print(post.text)



craigslist = open('./c_posts.txt', 'w')


for post in c_posts:
    craigslist.write(post.text)
    craigslist.write("\n")

craigslist.close()

