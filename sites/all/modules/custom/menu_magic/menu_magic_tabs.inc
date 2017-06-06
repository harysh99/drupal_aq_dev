<?php

/***
 * Page callback function
 */
function menu_magic_mtabs() {
  $build = array();
  $sample_txt = "<a href='/'>Click Me</a>";
  $items = array(
    t('Example of % placeholder = %text', array('%text' => $sample_txt)),
    t('Example of @ placeholder = @text', array('@text' => $sample_txt)),
    t('Example of ! placeholder = !text', array('!text' => $sample_txt)),
  );
  $build['tabs_element'] = array(
    '#type' => 'markup',
    '#markup' => theme('item_list', array('items' => $items)),
     );
  return $build;
}

/*
 *
 */
function menu_magic_rendered() {
  $build = array();
  $variables = array(
    'path' => 'http://placekitten.com/440/400',
    'title' => 'This is little kitten',
    'alt' => 'Alt text for kitten',
  );
  $build['img_element'] = array(
    '#type' => 'markup',
    '#markup' => theme('image', $variables),
    '#prefix' => '<div class ="kit_img">',
    '#suffix' => '</div>',
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'menu_magic') . '/menu_magic.css',
      ),
    ),
  );
  $build['rend_list'] = array(
    '#theme' => 'item_list',
    '#title' => 'This is a super list',
    '#items' => array(
      t('Are you enjoying this tutorial'),
      t('Yes indeed'),
      t('Nooooo way'),
      t('Current time is @time', array('@time' => date('r'))),
    ),
    '#cache' => array(
      'keys' => array('menu_magic', 'rend_list'),
      'bin' => 'cache',
      'expire' => time() + 30,
      'granularity' => DRUPAL_CACHE_PER_PAGE,
    ),
  );
  return $build;
}